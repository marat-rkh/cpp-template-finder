class Some {};

template<
    typename A,
    class B,
    int N,
    typename C = Some,
    typename = double
>
class Either
    : public Some {
    int i;
};

// template<A, B, int N, C = Some, _ = double>
// class Either
//     : public Some {
//     int i;
// };

int main(void) {
    int result = -1, val = 4;
    return result;
}
