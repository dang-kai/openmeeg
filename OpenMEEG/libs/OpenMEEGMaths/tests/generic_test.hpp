/*
Project Name : OpenMEEG

© INRIA and ENPC (contributors: Geoffray ADDE, Maureen CLERC, Alexandre
GRAMFORT, Renaud KERIVEN, Jan KYBIC, Perrine LANDREAU, Théodore PAPADOPOULO,
Emmanuel OLIVI
Maureen.Clerc.AT.sophia.inria.fr, keriven.AT.certis.enpc.fr,
kybic.AT.fel.cvut.cz, papadop.AT.sophia.inria.fr)

The OpenMEEG software is a C++ package for solving the forward/inverse
problems of electroencephalography and magnetoencephalography.

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's authors,  the holders of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
*/

#include <iostream>

#include <vector.h>

double eps = 1.e-12;

template <typename T>
void genericTest(const std::string& basename, T &M) {

    using namespace OpenMEEG;

    std::cout << " Generic Test " << std::endl;
    std::cout << "   nlin  = " << static_cast<int>(M.nlin()) << std::endl;
    std::cout << "   ncol  = " << static_cast<int>(M.ncol()) << std::endl;
    Vector v(M.ncol());
    v.set(1);
    v = M*v;

    std::cout << std::endl << "BASE :" << std::endl;
    M.info();

    // Test IO
    std::cout << std::endl << "BIN :" << std::endl;
    const std::string binname = basename+".bin";
    M.save(binname);
    M.load(binname);
    M.info();

    std::cout << std::endl << "TXT :" << std::endl;
    const std::string txtname = basename+".txt";
    M.save(txtname);
    M.load(txtname);
    M.info();

    // TODO Here for sparse matrix 

    const std::string matname = basename+".mat";
    std::cout << "MAT :" << std::endl;
    M.save(matname);
    M.load(matname);
    M.info();

    std::cout << "   operator * OK" << std::endl;
    std::cout.flush();
}
