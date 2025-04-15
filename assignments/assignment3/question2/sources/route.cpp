#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int inf = 0x3f3f3f3f;
struct Position
{
    union
    {
        int y;
        int h;
    };
    union
    {
        int x;
        int w;
    };

    Position(int ny = 0, int nx = 0) : y(ny), x(nx) {};
};
typedef Position Size;
Size size;
std::vector<int> costs = {0, 0};

int p2i(Position p)
{
    // start side
    if (p.y == -1 && p.x == -1)
    {
        return 0;
    }

    // end side
    if (p.y == -1 && p.x == inf)
    {
        return 1;
    }
    return p.y * size.w + p.x + 2;
};

std::vector<Position> get_neighbors(Position p)
{
    std::vector<Position> ret;

    // start side
    if (p.y == -1 && p.x == -1)
    {
        for (int y = 0; y < size.h; y++)
        {
            ret.push_back(Position(y, 0));
        }
        return ret;
    }

    // end side
    if (p.y == -1 && p.x == inf)
    {
        return ret;
    }

    // ordinary blocks
    if (p.y > 0)
        ret.push_back(Position(p.y - 1, p.x));
    if (p.y < size.h - 1)
        ret.push_back(Position(p.y + 1, p.x));
    if (p.x > 0)
        ret.push_back(Position(p.y, p.x - 1));
    if (p.x < size.w - 1)
        ret.push_back(Position(p.y, p.x + 1));
    if (p.x == size.w - 1)
        ret.push_back(Position(-1, inf));

    return ret;
}

int get_step(int c1, int c2)
{
    if (c1 >= c2 && c1 - c2 < 3)
    {
        return 0;
    }
    if (c1 - c2 == -1)
    {
        return 1;
    }
    return inf;
}

int get_cost(Position p, std::vector<bool> visited)
{

    visited.at(p2i(p)) = true;
    int ret = inf;

    if (p.y == -1 && p.x == inf)
    {
        ret = 0;
    }

    for (Position &neighbor : get_neighbors(p))
    {
        if (visited.at(p2i(neighbor)))
            continue;

        int tmp = get_cost(neighbor, visited) + get_step(costs.at(p2i(p)), costs.at(p2i(neighbor)));
        ret = (ret > tmp) ? tmp : ret;
    }

    return ret;
}

int main(void)
{

    std::vector<bool> visited = {false, false};

    std::string filename;
    std::getline(std::cin, filename);
    std::ifstream file(filename);
    file >> size.h >> size.w;
    int cost;
    for (int y = 0; y < size.h; y++)
    {
        for (int x = 0; x < size.w; x++)
        {
            file >> cost;
            costs.push_back(cost);
            visited.push_back(false);
        }
    }

    int res = get_cost(Position(-1, -1), visited);
    if (res == inf)
    {
        std::cout << 0 << std::endl;
    }
    else
    {
        std::cout << 1 << std::endl;
        std::cout << res << std::endl;
    }

    return 0;
}
