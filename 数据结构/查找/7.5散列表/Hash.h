#include <iostream>
#include <vector>
#include <string>

template <class Key, class Value>
struct HashData
{
    std::pair<Key, Value> _kv;
    HashData<Key, Value> *_next;
    HashData(const std::pair<Key, Value> &data) : _kv(data), _next(nullptr) {}
};

// 泛型仿函数
template <class Key>
struct HashKey
{
    // 默认仿函数将key转化为可以使用除留余数法的整数型，如果转化失败，需要用户自己提供转化函数
    int operator()(const Key &key) { return key; }
};
// 特化字符串类型的转化方式
template <>
struct HashKey<std::string>
{
    int operator()(const std::string &Str)
    {
        int Sum = 0;
        for (int i = 0; i < Str.size(); i++)
        {
            Sum += ((i + 1) * Str[i]); // 尽量避免冲突
        }
        return Sum;
    }
};

template <class Key, class Value, class HashFuc = HashKey<Key>>
class Hash
{
    typedef HashData<Key, Value> HashData;

private:
    std::vector<HashData *> _table;
    size_t _size; // 哈希表中的元素个数
public:
    Hash()
    {
        _size = 0;
        _table.resize(4);
        for (size_t i = 0; i < _table.size(); i++)
        {
            _table[i] = nullptr;
        }
    }

    ~Hash()
    {
        for (size_t i = 0; i < _table.size(); i++)
        {
            HashData *node = _table[i];
            if (node != nullptr)
            {
                HashData *next = node->_next;
                delete node;
                node = next;
            }
            _table[i] = nullptr;
        }
    }

    bool insert(const std::pair<Key, Value> &value)
    {
        HashFuc kot;
        HashData *node = _findPos(value);
        if (node != nullptr)
        {
            // 不允许相同值出现
            return false;
        }
        else
        {
            if (_size == _table.size())
            {
                // 装填因子为1，扩大哈希表，提高哈希效率
                std::vector<HashData *> buff;
                buff.resize(_table.size() * 2);
                // 重新计算映射关系
                for (size_t i = 0; i < _table.size(); i++)
                {
                    HashData *ptr = _table[i];
                    while (ptr != nullptr)
                    {
                        HashData *next = ptr->_next;
                        size_t new_pos = kot(ptr->_kv.first) % buff.size();
                        ptr->_next = buff[new_pos];
                        buff[new_pos] = ptr;
                        ptr = next;
                    }
                }
                _table.swap(buff);
            }
            size_t pos = kot(value.first) % _table.size();
            // 头插法
            HashData *data = new HashData(value);
            data->_next = _table[pos];
            _table[pos] = data;
            _size += 1;
            return true;
        }
    }

    bool erase(const Key &key)
    {
        HashFuc kot;
        size_t pos = kot(key.first) % _table.size();
        HashData *node = _table[pos];
        HashData *prev = nullptr;
        while (node != nullptr)
        {
            if (node->_kv.first != key)
            {
                prev = node;
                node = node->_next;
            }
        }
        if (node != nullptr)
        {
            if (prev == nullptr)
            {
                // 头删
                _table[pos] = node->_next;
                delete node;
            }
            else
            {
                prev->_next = node->_next;
                delete node;
            }
            return true;
        }
        else
        {
            // 无此元素
            return false;
        }
    }

    void disPlay()
    {
        for (size_t i = 0; i < _table.size(); i++)
        {
            HashData *node = _table[i];
            while (node != nullptr)
            {
                std::cout << node->_kv.first << ":" << node->_kv.second << " | ";
                node = node->_next;
            }
            std::cout << "\n";
        }
    }

    Value operator[](const Key &key)
    {
        HashData *find = _findPos(std::make_pair(key, Value()));
        if (find != nullptr)
        {
            return find->_kv.second;
        }
        else
        {
            // 没有找到这个元素，直接插入到哈希表中
            insert(std::make_pair(key, Value()));
            return Value();
        }
    }

private:
    HashData *_findPos(const std::pair<Key, Value> &value)
    {
        HashFuc kot;
        size_t pos = kot(value.first) % _table.size();
        HashData *cur = _table[pos];
        while (cur != nullptr)
        {
            if (cur->_kv.first == value.first)
            {
                break;
            }
            cur = cur->_next;
        }
        return cur;
    }
};
