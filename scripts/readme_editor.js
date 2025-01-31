const axios = require('axios');
const fs = require('fs');
const path = require('path');

async function updateReadme() {
    try {
        const solutionsPath = path.join(__dirname, '..', 'solutions');
        const files = fs.readdirSync(solutionsPath);
        const problemIds = files
            .filter(file => file.endsWith('.cpp'))
            .map(file => file.replace('.cpp', ''));

        const readmePath = path.join(__dirname, '..', 'README.md');
        let content = fs.readFileSync(readmePath, 'utf8');
        const lines = content.split('\n');
        const headerIndex = lines.findIndex(line => line.includes('|------|'));

        if (headerIndex !== -1) {
            const tableRows = [];
            
            // Get problem info for each solution file
            for (const problemId of problemIds) {
                try {
                    const solvedacResponse = await axios.get(`https://solved.ac/api/v3/problem/show?problemId=${problemId}`);
                    const problem = solvedacResponse.data;
                    
                    const newRow = `| ${problemId} | <img src="https://static.solved.ac/tier_small/${problem.level}.svg" width="20" height="20"> [${problem.titleKo}](https://www.acmicpc.net/problem/${problemId}) | [풀이](./solutions/${problemId}.cpp) | [해설]() |`;
                    tableRows.push(newRow);
                } catch (error) {
                    console.error(`Error fetching problem ${problemId}:`, error.message);
                }
            }
            
            // Sort rows by problem number
            const sortedRows = tableRows.sort((a, b) => {
                const numA = parseInt(a.split('|')[1].trim());
                const numB = parseInt(b.split('|')[1].trim());
                return numA - numB;
            });
            
            // Reconstruct content
            const newContent = [
                ...lines.slice(0, headerIndex + 1),
                ...sortedRows,
                ...lines.slice(headerIndex + 1 + tableRows.length)
            ].join('\n');
            
            fs.writeFileSync(readmePath, newContent);
            console.log('README.md 파일이 업데이트되었습니다.');
        }
    } catch (error) {
        console.error('Error:', error);
    }
}

updateReadme();