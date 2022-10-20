#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

template <typename EleType>
class SqlList
{
public:
    vector<EleType> _vet;
    size_t _length = 10;

    SqlList()
    {
        srand(time(NULL));
        std::cout << "before: " << std::endl;
        for (int i = 0; i < _length; i++)
        {
            _vet.push_back(rand() % 100 + 1);
            std::cout << _vet[i] << "";
        }
        std::cout << std::endl;
    }

    EleType operator[](const size_t pos)
    {
        return _vet[pos];
    }

    SqlList(const vector<EleType> &vet)
    {
        std::cout << "before: ";
        _length = vet.size();
        for (int i = 0; i < vet.size(); i++)
        {
            _vet.push_back(vet[i]);
            std::cout << vet[i] << " ";
        }
        std::cout << std::endl;
    }

    static void PrintVet(vector<EleType> &vet)
    {

        if (vet.size() == 0)
        {
            std::cout << "Empty" << std::endl;
        }
        for (int i = 0; i < vet.size(); i++)
        {
            std::cout << vet[i] << " ";
        }
        std::cout << std::endl;
    }

    void PrintVet()
    {
        // _length = _vet.size();
        if (_length == 0)
        {
            std::cout << "Empty" << std::endl;
        }
        for (int i = 0; i < _length; i++)
        {
            std::cout << _vet[i] << " ";
        }
        std::cout << std::endl;
    }
};