#include <iostream>
#include <vector>

std::string extractEncodedResult(const std::vector<std::vector<int> >& C, const std::string& input_string) {
    std::string encoded_result;
    int rows = C.size();
    int cols = C[0].size();

    for (int i = 0; i < rows; i++) {
        const std::vector<int>& row = C[i];
        int row_size = row.size();
        for (int j = 0; j < row_size; j++) {
            int index = row[j];
            if (index >= 1 && index <= input_string.length()) {
                encoded_result += input_string[index - 1];
            }
        }
    }

    return encoded_result;
}

int main() {
    int rows, cols;
    std::cout << "Nhap so hang cua ma tran C: ";
    std::cin >> rows;
    std::cout << "Nhap so cot cua ma tran C: ";
    std::cin >> cols;

    std::vector<std::vector<int> > C(rows, std::vector<int>(cols));
    std::cout << "Nhap cac phan tu cua ma tran C:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Phan tu C[" << i << "][" << j << "]: ";
            std::cin >> C[i][j];
        }
    }

    std::string input_string;
    std::cout << "Nhap chuoi can ma hoa: ";
    std::cin >> input_string;

    std::string encoded_result = extractEncodedResult(C, input_string);
    std::cout << "Ket qua ma hoa: " << encoded_result << std::endl;

    return 0;
}

