
fn SubArraySum (_input: [i32; 10],_target: i32)->[i32; 2]
{
    let mut _i: i32 = 0;
    let mut _j: i32 = 0;
    let mut _sum: i32 = 0;
    let arr_size = _input.len();
    while _i<arr_size as i32 && _j<arr_size as i32{
        if _target > _sum{
            _sum+=_input[_j as usize];
            _j=_j+1;
        }else if _target < _sum{
            _sum-=_input[_i as usize];
            _i=_i+1;
        }else{
            return [_i+1,_j];
        }
    }
    return [-1,0];
}

fn main()
{
    let _arr_input: [i32; 10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let _target = 100;
    let mut _output: [i32; 2] = SubArraySum(_arr_input,_target);
    if _output[0]==-1{
        println!("[{}]",_output[0]);
        println!("There is no subarray with sum {}",_target)
    }else{
        println!("[{},{}]",_output[0],_output[1]);
        println!("The sum of elements from {} to {} is {}.",_output[0],_output[1],_target);
    }
}