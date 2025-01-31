const axios = require('axios');
const fs = require('fs');
const path = require('path');

async function updateReadme() {
    try {
        // README.md 파일 읽기
        const readmePath = path.join(__dirname, '..', 'README.md');
        let content = fs.readFileSync(readmePath, 'utf8');
        const lines = content.split('\n');
        const headerIndex = lines.findIndex(line => line.includes('|------|'));
        
        // README.md 파일에서 기존 문제 번호 가져오기
        const existingProblems = new Set(
            lines.slice(headerIndex + 1)
                .filter(line => line.trim().startsWith('|'))
                .map(line => line.split('|')[1].trim())
        );

        // solutions 폴더에서 새로운 문제 번호 가져오기
        const solutionsPath = path.join(__dirname, '..', 'solutions');
        const files = fs.readdirSync(solutionsPath);
        const newProblemIds = files
            .filter(file => file.endsWith('.cpp'))
            .map(file => file.replace('.cpp', ''))
            .filter(id => !existingProblems.has(id));

        if (newProblemIds.length === 0) {
            console.log('새로운 문제가 없습니다.');
            return;
        }

        const tableRows = [];
        
        const existingRows = lines.slice(headerIndex + 1)
            .filter(line => line.trim().startsWith('|'));
        tableRows.push(...existingRows);

        // 새로운 문제 추가 - solved.ac API 사용
        for (const problemId of newProblemIds) {
            try {
                const solvedacResponse = await axios.get(`https://solved.ac/api/v3/problem/show?problemId=${problemId}`);
                const problem = solvedacResponse.data;
                
                const newRow = `| ${problemId} | <img src="https://static.solved.ac/tier_small/${problem.level}.svg" width="20" height="20"> [${problem.titleKo}](https://www.acmicpc.net/problem/${problemId}) | [풀이](./solutions/${problemId}.cpp) | [해설]() |`;
                tableRows.push(newRow);
                console.log(`문제 ${problemId} 추가됨`);
            } catch (error) {
                console.error(`Error fetching problem ${problemId}:`, error.message);
            }
        }
        
        // 문제 번호로 정렬
        const sortedRows = tableRows.sort((a, b) => {
            const numA = parseInt(a.split('|')[1].trim());
            const numB = parseInt(b.split('|')[1].trim());
            return numA - numB;
        });
        
        // README.md 파일 업데이트
        const newContent = [
            ...lines.slice(0, headerIndex + 1),
            ...sortedRows
        ].join('\n');
        
        fs.writeFileSync(readmePath, newContent);
        console.log('README.md 파일이 업데이트되었습니다.');
    } catch (error) {
        console.error('Error:', error);
    }
}

updateReadme();