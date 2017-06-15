class Some {};

template<
    typename A,
    class B,
    int N,
    template<class> class TT,
    typename C = Some,
    typename = double
>
class Either
    : public Some {
    int i;
};

// template<A, B, int N, template<_> class TT, C = Some, _ = double>
// class Either
//     : public Some {
//     int i;
// };

int main(void) {
    int result = -1, val = 4;
    return result;
}
