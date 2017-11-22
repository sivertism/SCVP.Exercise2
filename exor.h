#ifndef EXOR_H
#define EXOR_H

#include "systemc.h"
#include "nand.h"


SC_MODULE(exor)
{
    sc_signal<bool> h1, h2, h3;
    sc_in<bool> A, B;
    sc_out<bool> Z;

    nand a, b, c, d;

    SC_CTOR(exor):
    a("a"), b("b"), c("c"), d("d"), A("A"), B("B"), Z("Z")
    {
        a.A(A);
        c.A(A);

        a.B(B);
        b.B(B);

        a.Z(h1);
        c.B(h1);
        b.A(h1);

        c.Z(h2);
        d.A(h2);

        b.Z(h3);
        d.B(h3);

        Z(d.Z);

    }
};

#endif // EXOR_H
