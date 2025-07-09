# FindIt

A multithreaded file search engine built with C++ with a focus on clean architecture, OOP and concurrency.

## Features

- Recursively scans a directory for files
- Searches for a keyword within each file. 
- Runs the search in multiple threads to improve performance.
- Stores and displays the results.

## How it works

1. main() calls ThreadedSearchEngine::search
2. Gathers files with FileManager
3. Divides them among N threads
4. Each thread calls Searcher to look in files
5. Results are stored safely using a mutex
6. After joining threads, results are printed

## How to run

To build the project using CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

Then run the executable like this:

```bash
./FindIt <directory> <keyword>
```

Example:

```bash
./FindIt ../test test
```

Output:

```
File: ../test/file2.txt
 Line: 5
File: ../test/file1.txt
 Line: 5
File: ../test/subdir/file3.txt
 Line: 5
```

Output each file that contains matches, along with the line numbers where the keyword was found.
