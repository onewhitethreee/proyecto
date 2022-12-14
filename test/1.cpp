#include <fstream>
#include <iostream>

int main()
{
    const int BUFFER_SIZE = 4086;

    // Open the file
    std::ifstream input_file("ciencia.csv");

    // Check if the file was successfully opened
    if (!input_file)
    {
        std::cerr << "Error: failed to open file\n";
        return 1;
    }

    // Create a buffer to hold each line of the file
    char buffer[BUFFER_SIZE];

    // Read each line of the file
    for(int i=0; i<1000; i++){
        input_file.getline(buffer, BUFFER_SIZE);
        printf("%s\n", buffer);
    }/*正则匹配逗号前面的，中间的和后面的。 前面的就是书名，中间的就是作者名，最后的数字就是ISBN*/

    return 0;
}
