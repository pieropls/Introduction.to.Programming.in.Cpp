#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int> vect);
vector<size_t> lignes_max(vector<vector<int>> vect);
vector<vector<int>> tranches_max(vector<vector<int>> vect);

int main()
{
    return 0;
}

int somme_consecutifs_max(vector<int> vect)
{
    if (vect.empty()){
        return 0;
    }
    int sum_max = 0, current_sum = 0;
    for (int num : vect) {
        if (num == 0) {
            current_sum = 0;     // Reset when encountering a zero
        } else {
            current_sum += num;
            sum_max = max(sum_max, current_sum);
        }
    }
    return sum_max;
}


vector<size_t> lignes_max(vector<vector<int>> vect)
{
    vector<size_t> tab;
    if (vect.empty()){
        return tab;
    }
    int sum_max = 0;
    for (size_t i = 0; i < vect.size(); ++i) {
        int current_sum = somme_consecutifs_max(vect[i]);
        if (current_sum > sum_max) {
            tab.clear();
            sum_max = current_sum;
        }
        if (current_sum == sum_max) {
            tab.push_back(i);
        }
    }
    return tab;
}


vector<vector<int>> tranches_max(vector<vector<int>> vect)
{
    vector<vector<int>> max_lines;
    vector<size_t> max_lines_idx = lignes_max(vect);

    for(auto idx: max_lines_idx){
        max_lines.push_back(vect[idx]);
    }

    return max_lines;
}