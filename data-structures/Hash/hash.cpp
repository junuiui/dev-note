#include <iostream>
#include <unordered_map>
#include <unordered_set>

// Custom struct
struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Custom hash function for Point
struct PointHash {
    std::size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

int main() {
    std::cout << "--- unordered_map Example ---\n";
    std::unordered_map<std::string, int> freq;

    freq["apple"] = 2;
    freq["banana"] = 5;
    freq["apple"] += 1;

    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    std::cout << "\n--- unordered_set Example ---\n";
    std::unordered_set<int> seen;

    seen.insert(10);
    seen.insert(20);
    seen.insert(10); // duplicate, ignored

    for (int val : seen) {
        std::cout << val << "\n";
    }

    std::cout << "\n--- unordered_map with custom hash (Point) ---\n";
    std::unordered_map<Point, std::string, PointHash> pointMap;

    pointMap[{1, 2}] = "Start";
    pointMap[{3, 4}] = "End";

    for (const auto& entry : pointMap) {
        std::cout << "(" << entry.first.x << "," << entry.first.y << "): " << entry.second << "\n";
    }

    return 0;
}
