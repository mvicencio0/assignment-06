## Sorting

### Notes

- The functions described below may all be placed in the same file.  You should
  use `main()` to test these functions, and make sure they work properly.


### Requirements

#### Selection Sort

0. Write a function named `print_array` that takes as arguments the size of an
   array as an `int`, and an array as a `const int[]`, and has no return value.
   Given the following code:

   ```c++
   int a[7] = { 1, 2, 3, 4, 5, 6, 7, };
   print_array(7,a);
   cout << endl;   
   ```

   the function should produce the following output:

   ```
   ( 1 2 3 4 5 6 7 )
   ```

0. Write an in-place selection sort function named `selection_sort_in_place`
   that takes as arguments the size of an array as an `int`, and an array as an
   `int[]`.  (An in-place sorting algorithm is one that sorts the elements in
   the original container, as opposed to generating a sorted copy of all the
   elements and returning that.)  The algorithm is as follows:

   0. For the index of each element in the array (the "current index")

      0. Find the index of the minimum element at or after the current index.
      0. Swap the element at the current index with the smallest element found.

   For a more thorough explanation, google around, or see [the relevant
   Wikipedia entry](https://en.wikipedia.org/wiki/Selection_sort).

0. Write some code inside `main()` to test your selection sort function.  As a
   sample, the following code:

   ```c++
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
   ```

   should produce the following output:

   ```
   ( 1 2 3 4 5 6 7 )
   ( 1 2 3 4 5 6 7 )

   ( 22 1 63 67 11 17 12 )
   ( 1 11 12 17 22 63 67 )

   ( 45 53 64 7 25 79 54 )
   ( 7 25 45 53 54 64 79 )

   ( 34 21 35 84 16 10 36 )
   ( 10 16 21 34 35 36 84 )

   ( 41 2 85 94 69 9 92 )
   ( 2 9 41 69 85 92 94 )
   ```

#### Merge Sort

0. Overload the stream insertion operator for objects of type `vector<int> &`
   such that the following code:

   ```c++
   vector<int> v{ 1, 2, 3, 4, 5, 6, 7, };
   cout << v << endl;
   ```

   gives the following output:

   ```
   ( 1 2 3 4 5 6 7 )
   ```

0. Write a function named `merge_sort` that takes as an argument a `const
   vector<int> &` and returns a `vector<int>` containing all the elements of
   the vector that was passed as an argument, in ascending order.  The
   algorithm (which is recursive) is as follows:

   0. If the vector contains only 1 element, return the vector unchanged.
   0. Otherwise, split the vector into two halves, named `left` and `right`.
   0. Recursively sort each half (i.e. call `merge_sort(left);` and
      `merge_sort(right);`).
   0. Merge `left` and `right` into a new vector named `sorted`, in the
      following manner:

     0. As long as `left` and `right` both have elements not in `sorted`,
        compare the smallest such elements of each list, take the
        smaller of the two, and append it to `sorted`.
     0. Once all of the elements of either `left` or `right` are in `sorted`,
        take the leftover elements and append them to `sorted`.

   0. Return `sorted`.

   For a more thorough explanation, google around, or see [the relevant
   Wikipedia entry](https://en.wikipedia.org/wiki/Merge_sort).

0. Write some code inside `main()` to test your selection sort function.  As a
   sample, the following code:

   ```c++
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
   ```

   should produce the following output:

   ```
   ( 1 2 3 4 5 6 7 )
   ( 1 2 3 4 5 6 7 )

   ( 22 1 63 67 11 17 12 )
   ( 1 11 12 17 22 63 67 )

   ( 45 53 64 7 25 79 54 )
   ( 7 25 45 53 54 64 79 )

   ( 34 21 35 84 16 10 36 )
   ( 10 16 21 34 35 36 84 )

   ( 41 2 85 94 69 9 92 )
   ( 2 9 41 69 85 92 94 )
   ```


##### Notes

- You will probably need to read more about
  [`std::vector`](http://en.cppreference.com/w/cpp/container/vector)
  (here's a nice
  [tutorial](http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm).

- You will probably need to search around for the best way to split a vector
  into two smaller vectors (here's an
  [answer](http://stackoverflow.com/a/9811343) from stackoverflow).

- If you wish, perhaps for an extra challenge, instead of using the `vector`
  class as described above, you may use the linked list class that you wrote in
  assignment-04.


### Style

- Place your solution in a `solution--YOURNAME` subdirectory, or in the base
  directory.

- Document and format your code well and consistently.
- Wrap lines at 79 or 80 columns whenever possible.
- End your file with a blank line.
- Do *not* use `using namespace std;`.  You may get around typing `std::` in
  front of things or with, e.g., `using std::cout;`.

- Include your copyright and license information at the top of every file,
  followed by a brief description of the file's contents, e.g.

  ```c++
  /* ----------------------------------------------------------------------------
   * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
   * Released under the [MIT License] (http://opensource.org/licenses/MIT)
   * ------------------------------------------------------------------------- */

  /**
   * A short program to print "Hello World!" to standard output.
   */
  ```


-------------------------------------------------------------------------------
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)]
(http://creativecommons.org/licenses/by/4.0/)  
Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>  
This work is licensed under a [Creative Commons Attribution 4.0 International
License] (http://creativecommons.org/licenses/by/4.0/)  
Project located at <https://github.com/2015-fall-csuf-benblazak-cpsc-121>

