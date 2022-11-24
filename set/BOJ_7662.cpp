#include <iostream>
#include <set>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for (int t = 0; t < T; t++){
        int n;
        cin >> n;
        multiset<int> ms;
        for (int i = 0; i < n; i++){
            char type;
            int input;
            cin >> type >> input;
            if(type == 'I'){ // 삽입
                ms.insert(input);
            }
            else{ // 샥제
                if(input == 1 && !ms.empty()){ // 최대값 삭제
                    ms.erase(ms.find(*(ms.rbegin())));
                }
                if(input == -1 && !ms.empty()){ // 최소값 삭제
                    ms.erase(ms.find(*(ms.begin())));
                }
            }
        }
        if(ms.empty())
            cout << "EMPTY\n";
        else
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
     }
}
/*


1. find를 이용한 중복된값 단일제거
erase은 인자값으로 iter와 value 모두 받는다.
인자로 value를 넣게되면 해당 value과 같은 값을 가지는 요소들을 모두 삭제하기 때문에 itr로 접근해야 한다.
따라서 find를 통해 특정값의 itr를 구하고 이것을 erase에 인자로 전달하여 하나의 요소만 삭제하도록 한다.

2. rbegin end 차이
end는 past-the-end의 iterator 즉, 마지막 원소의 다음 주소를 가리킨다.
past-the-end를 사용함으로써 컨테이너의 탐색을 용이하게 하고 (itr가 end()가리킬때까지 반복)
컨테이너 내부가 비었을때 begin과 end가 같은 값을 가리키도록 하기 때문이다.
따라서 마지막 원소를 삭제할때는 end()보다 한칸 앞에 있는 값을 지정해야하므로 --end()로 접근하거나 rbegin()을 사용한다.
*/
