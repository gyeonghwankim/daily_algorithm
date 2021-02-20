function solution(brown, yellow) {
    var answer = [];
    let width = 1;
    
    while(true){
        if((yellow % width) === 0) {
            let height = yellow / width;
            let border = width * 2 + height * 2 + 4;
            if(brown === border) {
                answer = [width+2, height+2].sort((a,b) => b-a);
                break;
            }
        }
        
        width = width + 1;
    }
    
    return answer;
}