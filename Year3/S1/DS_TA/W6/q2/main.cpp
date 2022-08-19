/**
 * File System
 * 
 * @Description:
 * Please use the class "GeneralTree" to simulate a Unix File System.
 * Reference: https://www.geeksforgeeks.org/unix-file-system/
 * But only Ordinary files and Directories will appear in the File System, which is determined by the tag "type" which is "dir" or "file"
 * 
 * There are five operations you need to do:
 * 1. mv <source> <destination>
 *  - move the file or directory from <source> to under <destination>
 *  - Replace the files of <destination> if it exists
 *  - Cancel operation if <source> does not exist.
 * 2. cp <source> <destination>
 *  - copy the file or directory from <source> to under <destination>
 *  - Replace the files of <destination> if it exists
 *  - Cancel operation if <source> does not exist.
 * 3. rm <destination>
 *  - remove the file or directory from <destination>
 *  - Cancel operation if <destination> does not exist.
 * 4. touch <destination> <data>
 *  - add a file to <destination> that contains <data>
 *  - Create directories which in the path if it does not exist.
 *  - Replace the files of <destination> if it exists.
 * 5. mkdir <destination>
 *  - add a directory to <destination>
 *  - Create directories which in the path if it does not exist.
 *  - Cancel operation if <destination> already exist.
 * <source> and <destination> are both absolute pathnames.
 * <data> is a string, could be empty.
 * 
 * Serialized property of node for File:
 * {
 *  "data":"<data for the file>",
 *  "path":"<relative pathnames for this node>",
 *  "type":"file"
 * }
 * 
 * Serialized property of node for Directory:
 * {
 *  "children":[<children of this node>],
 *  "path":"<relative pathnames for this node>",
 *  "type":"dir"
 * }
 * 
 * You can add any function or variable if you want.
 * Note: You must use your own "GeneralTree" class or you will get up to 0 points.
 * 
 * @Input Description
 * The first line of input is the serialized string of the GeneralTree.
 * The following line til the end will be the operations, one operation per line.
 * 
 * @Output Description
 * A serialized string of the GeneralTree after operations with a "\n".
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  return 0;
}
