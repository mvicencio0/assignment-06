/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * An implementation of merge sort, along with a few very simple tests.
 */

#include <vector>
#include <iostream>

using std::cout;
using std::endl;

using std::vector;

// ----------------------------------------------------------------------------

void print_array(int size, const int a[]) {
    cout << "( ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << ")";
}

std::ostream & operator<<(std::ostream & os, const vector<int> & v) {
    os << "( ";
    for (const int & i : v)
        os << i << " ";
    os << ")";

    return os;
}

// ----------------------------------------------------------------------------

// - selection sort has a best, worst, and average case time complexity of
//   O(n*n).  this is because, for a list of n elements, we iterate through
//   (at least part of) the array n times: once for each element we put in the
//   sorted list.

void selection_sort_in_place(int size, int a[]) {

    // for the index of each element in the array (the "current index")
    for ( int first_unsorted = 0;
          first_unsorted < size;
          first_unsorted++ ) {

        // find the index of the minimum element at or after the current index
        int index_of_min = first_unsorted;

        for ( int first_uncompared = first_unsorted;
              first_uncompared < size;
              first_uncompared++ ) {

            if ( a[index_of_min] > a[first_uncompared] )
                index_of_min = first_uncompared;
        }

        // swap the element at the current index with the smallest element
        // found
        int temp = a[first_unsorted];
        a[first_unsorted] = a[index_of_min];
        a[index_of_min] = temp;
    }
}

// ----------------------------------------------------------------------------

// - merge sort has a best, worst, and average case time complexity of
//   O(n*log(n))
// - for a discussion of the time complexity analysis, see
//   <http://stackoverflow.com/a/17436398>, and maybe do some googling.  time
//   complexity analysis of recursive algorithms is not (usually) a simple
//   thing.

vector<int> merge_sort(const vector<int> & v) {
    // base case
    if (v.size() < 2)
        return v;

    // split
    vector<int> left{ v.begin(), v.begin()+v.size()/2 };
    vector<int> right{ v.begin()+v.size()/2, v.end() };

    // recursively sort each side
    left = merge_sort(left);
    right = merge_sort(right);

    // merge
    vector<int> sorted;
    vector<int>::iterator l = left.begin();
    vector<int>::iterator r = right.begin();
    while( l != left.end() && r != right.end() )
        if (*l < *r)
            sorted.push_back(*(l++));
        else
            sorted.push_back(*(r++));
    while( l != left.end() )
        sorted.push_back(*(l++));
    while( r != right.end() )
        sorted.push_back(*(r++));

    return sorted;
}

// ----------------------------------------------------------------------------

int main() {
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, };
    cout << v << endl;

    // test selection sort

    int arrays[5][7] = {
        { 1, 2, 3, 4, 5, 6, 7 },
        { 22, 1, 63, 67, 11, 17, 12, },
        { 45, 53, 64, 7, 25, 79, 54, },
        { 34, 21, 35, 84, 16, 10, 36, },
        { 41, 2, 85, 94, 69, 9, 92, },
    };

    for (int i = 0; i < 5; i++) {
        print_array(7, arrays[i]);
        cout << endl;

        selection_sort_in_place(7, arrays[i]);

        print_array(7, arrays[i]);
        cout << endl;

        cout << endl;
    }

    cout << "-------\n\n";

    // test merge sort

    vector<int> vectors[] = {
        vector<int>{ 1, 2, 3, 4, 5, 6, 7 },
        vector<int>{ 22, 1, 63, 67, 11, 17, 12, },
        vector<int>{ 45, 53, 64, 7, 25, 79, 54, },
        vector<int>{ 34, 21, 35, 84, 16, 10, 36, },
        vector<int>{ 41, 2, 85, 94, 69, 9, 92, },
    };

    for (const vector<int> & v : vectors) {
        cout << v << endl;
        cout << merge_sort(v) << endl;
        cout << endl;
    }

    return 0;
}

