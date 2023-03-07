// #include <stdio.h>
// #include <string.h>
#include <iostream>
#include <cstring>
#include <vector>


//using namespace std;

// // 0 1 2 3
// // 0x00 0x00 0x01 0xd3
// template<typename T>
// void encode(std::vector<uint8_t>& buffer, int16_t& iterator, T value)
// {
//     for (unsigned i = 0, j = 0; i < sizeof T; i++)
//     {
//         buffer[(iterator)++] = (value >> ((sizeof T * 8) - 8) - ((i == 0) ? j : j += 8));
//     }
// }

// 0x00 0x00 0x01 0xd3
template<typename T>
void encode(std::vector<uint8_t>& buffer, int16_t& iterator, T value) {
    size_t sizeT = sizeof(T);
    buffer.resize(buffer.size() + sizeT);
    T* itemPtr = reinterpret_cast<T*>(&buffer[iterator]);
    *itemPtr = value;
    iterator += sizeT;
}
template<typename T>
T decode(const std::vector<uint8_t>& buffer, int16_t& it) {
    const T* pResult = reinterpret_cast<const T*>(&buffer[it]);
    it += sizeof(T);
    return *pResult;
}
void main() {
    std::vector<uint8_t> data; int16_t iterator = 0;
    int32_t n = 1234567890;  int32_t n2 = 44444444;
    encode(data, iterator, n);
    encode(data, iterator, n2);
    int16_t itDecode = 0;
    int32_t read1 = decode<int32_t>(data, itDecode);
    int32_t read2 = decode<int32_t>(data, itDecode);
    printf("read1=\t%d\n", read1);
    printf("read2=\t%d\n", read2);
}
