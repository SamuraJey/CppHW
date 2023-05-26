#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    int numRows, numCols;
    int posOfOne = -1;

    std::cin >> numRows >> numCols;

    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols));
    std::for_each(matrix.begin(), matrix.end(), [](auto &row) {
        std::for_each(row.begin(), row.end(), [](auto &cell) {
            std::cin >> cell;
        });
    });

    for (int i = 0; i < numRows; i++)
    {
        if (std::any_of(matrix[i].begin(), matrix[i].end(), [](int cell) { return cell == 1; }))
        {
            posOfOne = i;
            break;
        }
    }

    std::vector<std::string> operations;
    for (int dstCol = 0; dstCol < numCols; dstCol++)
    {
        int minCol = std::distance(matrix[posOfOne].begin(), std::min_element(matrix[posOfOne].begin() + dstCol, matrix[posOfOne].end()));
        if (minCol != dstCol)
        {
            for (auto &row : matrix)
            {
                row[minCol] = std::exchange(row[dstCol], row[minCol]);
            }
            std::stringstream strStream;
            strStream << "C " << dstCol + 1 << " " << minCol + 1;
            operations.push_back(strStream.str());
        }
    }

    for (int dstRow = 0; dstRow < numRows; dstRow++)
    {
        int minRowVal = matrix[dstRow][0];
        int minRow = dstRow;
        for (int i = dstRow; i < numRows; i++)
        {
            if (matrix[i][0] < minRowVal)
            {
                minRowVal = matrix[i][0];
                minRow = i;
            }
        }
        if (minRow != dstRow)
        {
            std::swap(matrix[minRow], matrix[dstRow]);
            std::stringstream strStream;
            strStream << "R " << dstRow + 1 << " " << minRow + 1;
            operations.push_back(strStream.str());
        }
    }

    std::cout << operations.size() << std::endl;
    for (const auto &operation : operations)
    {
        std::cout << operation << std::endl;
    }

    return 0;
}