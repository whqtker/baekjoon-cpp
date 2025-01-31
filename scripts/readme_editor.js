// 사용 방법
// node scripts/readme_editor.js <문제번호>

const axios = require('axios');
const fs = require('fs');
const path = require('path');

async function updateReadme(problemId) {
    try {
        // solved.ac API를 통해 문제 정보 가져오기
        const solvedacResponse = await axios.get(`https://solved.ac/api/v3/problem/show?problemId=${problemId}`);
        const problem = solvedacResponse.data;
        
        // 새로운 행 생성
        const newRow = `| ${problemId} | <img src="https://static.solved.ac/tier_small/${problem.level}.svg" width="20" height="20"> [${problem.titleKo}](https://www.acmicpc.net/problem/${problemId}) | [풀이](./solutions/${problemId}.cpp) | [해설]() |\n`;
        
        // README.md 파일 읽기
        const readmePath = path.join(__dirname, '..', 'README.md');
        let content = fs.readFileSync(readmePath, 'utf8');
        
        // 테이블 행 추가
        const lines = content.split('\n');
        const headerIndex = lines.findIndex(line => line.includes('|------|'));
        
        if (headerIndex !== -1) {
            const tableRows = lines.slice(headerIndex + 1).filter(line => line.trim().startsWith('|'));
            
            tableRows.push(newRow);
            
            const sortedRows = tableRows.sort((a, b) => {
                const numA = parseInt(a.split('|')[1].trim());
                const numB = parseInt(b.split('|')[1].trim());
                return numA - numB;
            });
            
            const newContent = [
                ...lines.slice(0, headerIndex + 1),
                ...sortedRows,
                ...lines.slice(headerIndex + 1 + tableRows.length)
            ].join('\n');
            
            fs.writeFileSync(readmePath, newContent);
            console.log(`문제 번호 ${problemId} 가 README.md 파일에 추가되었습니다.`);
        }
    } catch (error) {
        console.error('Error:', error);
    }
}

// 문제 번호를 인자로 받고 생성된 행을 README.md 파일에 추가
const problemId = process.argv[2];
if (problemId) {
    updateReadme(problemId);
} else {
    console.log('문제 번호를 입력해주세요.');
}