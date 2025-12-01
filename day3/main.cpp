#include <iostream>
#include <string>
#include <vector>

int extract_digit(const std::vector<std::string>& grid, int r, int c) {
    static int cols = grid[0].size();
    
    while (c >= 0 && isdigit(grid[r][c])) {
        c--;
    }
    c++;
    int next_space = c;
    while (next_space < cols && isdigit(grid[r][next_space])) {
        next_space++;
    }
    return std::stoi(grid[r].substr(c, next_space - c));
}

int main() {
    int sum = 0;
    std::string line;

    std::vector<std::string> grid;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        
        grid.push_back(line);
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    constexpr int dr[] = { -1,-1,-1,  1, 1, 1, 0,  0 };
    constexpr int dc[] = { -1, 0, 1, -1, 0, 1, 1, -1 };
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '*') {
                int adjacent_nums = 0;
                bool prev_was_num = false;
                unsigned long long product = 1;

                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (!prev_was_num && std::isdigit(grid[nr][nc])) {
                            adjacent_nums++;
                            prev_was_num = true;
                            product *= extract_digit(grid, nr, nc);
                        }
                        else if (!std::isdigit(grid[nr][nc]) ) {
                            prev_was_num = false;
                        }
                    }

                    bool should_reset = (i % 3) == 2 || i >= 6;
                    prev_was_num = prev_was_num && !should_reset;
                }

                if (adjacent_nums == 2) {
                    sum += product;
                }
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}