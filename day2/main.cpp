#include <iostream>
#include <unordered_map>
int main() {
    unsigned long long sum = 0;
    std::unordered_map<char, int> counts = {
        {'r', 0}, {'b', 0}, {'g', 0}
    };

    std::string line;
    while (std::getline(std::cin, line)) {
        if(line.empty()) {
            break;
        }

        counts['r'] = 0;
        counts['b'] = 0;
        counts['g'] = 0;

        int index = line.find(':');
        int game_id = std::stoi(line.substr(5, index - 5));
        // std::cout << "Game ID: " << game_id << std::endl;

        while(index < line.size()) {
            
            if(std::isdigit(line[index])) {
                int next_space = line.find(' ', index);
                int val = std::stoi(line.substr(index, next_space - index));
                
                index = next_space + 1;
                counts[line[index]] = std::max(counts[line[index]], val);
            }

            index++;
            // if(line[index] == ' ') {
            //     index++;
            //     continue;
            // }
        }

        sum += counts['r'] * counts['b'] * counts['g'];
    }

    std::cout << sum << std::endl;

    return 0;
}