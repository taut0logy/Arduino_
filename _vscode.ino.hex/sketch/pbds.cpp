#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\pbds.cpp"
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k) : returns iterator to kth element starting from 0
// order_of_key(k) : returns count of elements strictly smaller than k

int main() {
    ordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    s.insert(10);
    s.insert(15);

    // find the k-th smallest element
    cout << *s.find_by_order(2) << endl; // output: 4

    // find the number of elements less than x
    cout << s.order_of_key(5) << endl; // output: 2

    // erase an element
    s.erase(4);

    // find the largest element less than or equal to x
    cout << *s.lower_bound(5) << endl; // output: 3

    return 0;
}

//end(x)==x.find_by_order(x.size())