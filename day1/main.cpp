#include <iostream>


bool checkString(std::string& line, std::string pattern, int direction, int index) {
    int endpoint = direction * pattern.size() + index + 1;
    if(endpoint < 0 || endpoint > line.size()) {
        return false;
    }   

    if(direction == -1) {
        return line.substr(endpoint, pattern.size()) == pattern;
    }
    else{
        return line.substr(index, pattern.size()) == pattern;
    }
}

int checkDigit(std::string& line, int direction, int index) {
   if(line[index] >= '0' && line[index] <= '9') return line[index] - '0';
   
   if(checkString(line, "one", direction, index)) {
    return 1;
   }
   if(checkString(line, "two", direction, index)) {
    return 2;
   }
   if(checkString(line, "three", direction, index)) {
    return 3;
   }
   if(checkString(line, "four", direction, index)) {
    return 4;
   }
   if(checkString(line, "five", direction, index)) {
    return 5;
   }
   if(checkString(line, "six", direction, index)) {
    return 6;
   }
   if(checkString(line, "seven", direction, index)) {
    return 7;
   }
   if(checkString(line, "eight", direction, index)) {
    return 8;
   }
   if(checkString(line, "nine", direction, index)) {
    return 9;
   }
   return -1;
}

int main() {
    int sum = 0;
    std::string line;
    while(std::getline(std::cin, line)) {
        if(line.empty()) {
            break;
        }

        int leftDigit = 0;
        int index = 0;
        while(index < line.size()) {
            leftDigit = checkDigit(line, 1, index);
            if(leftDigit != -1) {
                break;
            }
            index++;
        }
        int rightDigit= 0;
        index = line.size() - 1;
        while(index >= 0) {
            rightDigit = checkDigit(line, -1, index);
            if(rightDigit != -1) {
                break;
            }
            index--;
        }
        // std::cout << leftDigit << rightDigit << std::endl; 
        sum += (10 * leftDigit) + rightDigit;
    }

    std::cout << sum << std::endl;
    return 0;
}