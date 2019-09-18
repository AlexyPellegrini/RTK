#!/bin/bash -x
export CXXFLAGS="-fPIC -std=c++11"
ctest -R "(rtk|RTK)" -S /home/srit/src/rtk/rtk-dashboard/russula_build_rtk_in_itk.cmake -V
ctest -R "(rtk|RTK)" -S /home/srit/src/rtk/rtk-dashboard/russula_tbb.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_shared_itk-v4.12.0.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_itk-v4.12.0.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_shared_itk-v4.13.1_nocuda.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_shared_itk-v4.13.1.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_itk-v4.13.1.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_shared.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_debug.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_style.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_doxygen.cmake -V
rsync -e 'ssh -i /home/srit/.ssh/nophrase' -a --delete \
    /home/srit/src/rtk/dashboard_tests/RTK-Doxygen/Doxygen/html \
    ssh.creatis.insa-lyon.fr:/home/srit/src/rtk/dashboard_tests/RTK-Doxygen/Doxygen
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_nocuda_valgrind.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_cuda_valgrind.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_cuda_cov.cmake -V
ctest -S /home/srit/src/rtk/rtk-dashboard/russula_suse_gcc_space.cmake -V

