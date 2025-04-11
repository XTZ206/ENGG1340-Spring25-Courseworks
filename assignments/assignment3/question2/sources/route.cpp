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

std::vector<Position> neighbors(Position p)
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

double consumption(Position p, std::vector<double> &obstacles, std::vector<bool> visited)
{

    visited.at(p2i(p)) = true;
    double ret = inf;

    if (p.y == -1 && p.x == inf)
    {
        ret = 0;
    }

    for (Position &neighbor : neighbors(p))
    {
        if (visited.at(p2i(neighbor)))
            continue;

        if (obstacles.at(p2i(neighbor)) - obstacles.at(p2i(p)) > 1.5 ||
            obstacles.at(p2i(p)) - obstacles.at(p2i(neighbor)) > 2.5)
            continue;

        double c = consumption(neighbor, obstacles, visited);
        double s = obstacles.at(p2i(neighbor)) > obstacles.at(p2i(p)) ? obstacles.at(p2i(neighbor)) - obstacles.at(p2i(p)) : 0;
        ret = (ret > c + s) ? (c + s) : ret;
    }

    return ret;
}

int main(void)
{

    std::vector<double> obstacles = {0, 0};
    std::vector<bool> visited = {false, false};

    std::string filename;
    std::getline(std::cin, filename);
    std::ifstream file(filename);
    file >> size.h >> size.w;
    double obstacle;
    for (int y = 0; y < size.h; y++)
    {
        for (int x = 0; x < size.w; x++)
        {
            file >> obstacle;
            obstacles.push_back(obstacle);
            visited.push_back(false);
        }
    }

    double res = consumption(Position(-1, -1), obstacles, visited);
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
