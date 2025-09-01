#!python3

def SubArraySum (input,target):
    arr_size = len(input)
    i=0
    j=0
    sum=0
    while i<arr_size and j<arr_size:
        if target > sum:
            sum+=input[j]
            j+=1
        elif target < sum:
            sum-=input[i]
            i+=1
        else:
            return [i+1,j]
    return [-1]

arr_input = [1,2,3,4,5,6,7,8,9,10]
target = 100;
output = SubArraySum(arr_input,target)
if output[0] == -1:
    print("[",output[0],"]")
    print("There is no subarray with sum",target,".")
else:
    print("[",output[0],",",output[1],"]")
    print("The sum of elements from",output[0],"to",output[1],"is",target,".")