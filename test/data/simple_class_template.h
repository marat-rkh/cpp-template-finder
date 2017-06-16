class One {};

template<
    typename A,
    class B,
    int N,
    template<class> class TT,
    typename C = One,
    typename = double
>
class Two
    : public One {
    int i;
};

// template<A, B, int N, template<_> class TT, C = Some, _ = double>
// class Two
//     : public Some {
//     int i;
// };
