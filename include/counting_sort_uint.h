#pragma once

#include <vector>
 
//자연수만 받을 수 있는 버전입니다.
template <class Container, class IntT>
void counting_sort_uint(Container& con, IntT max_num)
{
    //카운팅용 배열
    std::vector<IntT> counting_array(max_num + 1, 0); //0까지 포함
 
    //셉니다.
    for (const auto& e : con)
        counting_array[e]++;
 
    //도로 넣습니다.
    IntT i = 0;
    for (auto& e : con)
    {
        bool pushed = false; //넣었는지 확인하는 플래그입니다.
 
        while (!pushed) //하나 넣을때까지 돕니다.
            if (counting_array[i] == 0) //0이면 지나갑니다.
                i++;
            else //있으면 넣습니다.
            {
                e = i; //넣고
                counting_array[i]--; //넣었으니까 빼고
                pushed = true; //됐으니까 나갑니다.
                continue;
            }
    }
}
