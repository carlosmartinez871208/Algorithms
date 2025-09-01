#include <iostream>
#include <ostream>
#include <vector>

class Indexes_SubArraySum
{
    public:
        std::vector<int> SubArraySum(std::vector<int> &arr, int target) {
            int arr_size = arr.size();
            int i=0,j=0,sum=0;
            while(i<arr_size&&j<arr_size){
                if(target > sum){
                    sum += arr[j];
                    j++;
                }else if(target < sum){
                    sum -= arr[i];
                    i++;
                }else{
                    return {i+1,j};
                }
            }
            return {-1};
        }
};

int main (int argc, char** argv)
{
    Indexes_SubArraySum arr_analysis;
    std::vector<int> arr_input = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> arr_output;
    int target = 13;
    arr_output = arr_analysis.SubArraySum(arr_input,target);
    if(arr_output[0] == -1){
        std::cout<<"["<<arr_output[0]<<"]"<< std::endl;
        std::cout<<"There is no subarray with sum "<<target<<"."<<std::endl;
    }else{
        std::cout<<"["<<arr_output[0]<<","<<arr_output[1]<<"]"<< std::endl;
        std::cout<<"The sum of elements from "<<arr_output[0]<< " to "<<arr_output[1]<<" position is "<<target<<"."<<std::endl;
    }
    return EXIT_SUCCESS;
}
