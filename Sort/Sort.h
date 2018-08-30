#include<vector>
using namespace std;

template <typename T>
class Sort 
{
public:
    void insertSort(vector<T>& data);
    void binaryInsertSort(vector<T>& data);

private:

};

template <typename T>
void Sort<T>::insertSort(vector<T>& data)
{ 
    for (int i = 1; i < data.size(); ++i)
    {   
        T curr = data[i];
        int j = i;
        for(; j > 0 && curr < data[j-1]; --j)
                data[j] =  data[j-1];
        data[j] = curr;
    }
}

template <typename T>
void Sort<T>::binaryInsertSort(vector<T> &data)
{
    T curr; 
    int lo, hi, mid;
    for (int i = 0; i < data.size(); ++i)
    {
        curr = data[i];
        lo = 0; hi = i-1;
        while(lo <= hi)
        {
            mid = lo + (hi-lo)/2;
            if (curr < data[mid])
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        for (int j = i-1; j > hi; --j)
            data[j+1] = data[j];
        data[hi+1] = curr;
    }
}