#include <iostream>
using namespace std;

int tilingways(int n)
{
    if (n<3 && n>0)
    {
        return n;
    }
    
    return tilingways(n-1) + tilingways(n-2);
}
int main()
{
    cout<<tilingways(4);
    return 0;
}