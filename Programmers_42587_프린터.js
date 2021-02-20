function solution(priorities, location) {
    var answer = 1;
    let currentIndex = 0;
    let ret = 1;
    
    const arr = priorities.map(item => [item, false]);
    const sorted = priorities.sort((a, b) => b - a);
    
    while(true){
        let flag = false;
        arr.forEach((element, index) => {
            if(element[1] === false && sorted[currentIndex] === element[0]){
                if(index === location) {
                    flag = true;
                    ret = answer;
                }
                else {
                    currentIndex = currentIndex + 1;
                    answer = answer + 1;
                    arr[index][1] = true;
                    
                }
            }
        })
        
        if(flag) break;
    }
    
    return ret;
}