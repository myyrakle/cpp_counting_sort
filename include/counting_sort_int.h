#pragma once

#include <vector>
 
//-max ~ +max 양수 음수 둘다 받습니다.
template <class Container, class IntT>
void counting_sort(Container& con, IntT max_num)
{
    //카운팅용 배열
    std::vector<IntT> counting_positive(max_num+1,0); //0까지 포함
    std::vector<IntT> counting_negative(max_num, 0); //0 제외
    
    //셉니다.
    for (const auto& e : con)
    {
        if (e<0) //음수일 경우
            counting_negative[-e]++;
        else //0이나 자연수일 경우
            counting_positive[e]++;
    }
 
    //도로 넣습니다.
    IntT i = 0; //자연수 전용 반복자입니다.
    IntT neg_i = max_num - 1; //음수 전용 반복자입니다.
    for (auto& e : con)
    {
        bool pushed = false; //넣었는지 확인하는 플래그입니다.
 
        while (!pushed) //하나 넣을때까지 돕니다.    
            if (neg_i>0) //음수 먼저 처리합니다.
                if (counting_negative[neg_i] == 0) //0이면 지나갑니다.
                    neg_i--;
                else
                {
                    e = -(neg_i + 1); //인덱스 고려해서 넣고
                    counting_negative[neg_i]--; //넣었으니까 빼고
                    pushed = true; //됐으니까 나갑니다.
                }
            
            else //음수 다 처리하고 양수를 처리합니다.
                if (counting_positive[i] == 0) //0이면 지나갑니다.
                    i++;
                else //있으면 넣습니다.
                {
                    e = i; //넣고
                    counting_positive[i]--; //넣었으니까 빼고
                    pushed = true; //됐으니까 나갑니다.
                }
    }
}
