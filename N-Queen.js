/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    const solutions = getNQueensResult(n, 0, [], [])
    return solutions;
};

function getNQueensResult(n, row, choices, solutions) {
    if(row === n) {
        const processedChoices = processChoices(choices);
        solutions.push(processedChoices);    
        
        return solutions
    } else {
        for(let i = 0; i < n; i++) {
            choices.push(i);
            if(isValid(choices)) {
                solutions = getNQueensResult(n, row+1, choices, solutions);
            }
            choices.pop();
        }
    }
    
    return solutions
}
function processChoices(choices) {
    const stringChoices = [];

    for(let i = 0; i < choices.length; i++) {
        stringChoices.push('');
    }
    
    for(let i = 0; i < stringChoices.length; i++) {
      for(let j = 0; j < stringChoices.length; j++) {
        if(choices[i] === j) stringChoices[i] += 'Q';
        else stringChoices[i] += '.';
      }

    }
    return stringChoices
}


function isValid(choices) {
    const row = choices.length-1;
    const column = choices[choices.length-1];

    for(let i = 0; i < choices.length-1; i++) {
        const currentRow = i;
        const currentCol = choices[i];
        const leftCollisionIndex = currentCol - (row - currentRow);
        const rightCollisionIndex = currentCol + (row - currentRow);
        
        if(column === currentCol) return false;
        if(column === leftCollisionIndex || column === rightCollisionIndex) return false;
    }
   return true; 
}
