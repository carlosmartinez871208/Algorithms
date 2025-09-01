function SubArraySum (input,target){
    let output = new Array();
    let arr_size = input.length;
    let i=0,j=0,sum=0;
    while (i<arr_size&&j<arr_size){
        if(target > sum){
            sum += input.at(j);
            j++;
        }else if(target < sum){
            sum -= input.at(i);
            i++;
        }else{
            output[0] = i+1;
            output[1] = j;
            return output;
        }
    }
    output[0]=-1;
    return output;
}

const target = 5;
const arr_input = new Array(1,2,3,4,5,6,7,8,9,10);
let output = SubArraySum(arr_input,target);
if(-1 == output.at(0)){
    console.log(`[${output.at(0)}]`);
    console.log(`There is no subarray with sum ${target}.`);
}else{
    console.log(`[${output.at(0)},${output.at(1)}]`);
    console.log(`The sum of elements from ${output.at(0)} to ${output.at(1)} is ${target}.`);
}
