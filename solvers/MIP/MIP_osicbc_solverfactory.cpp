#include <minizinc/solvers/MIP/MIP_osicbc_solverfactory.hh>
#include <minizinc/solvers/MIP/MIP_osicbc_wrap.hh>
#include <minizinc/solvers/MIP/MIP_solverinstance.hh>

namespace MiniZinc {
namespace {
void getWrapper() { static MIP_SolverFactory<MIP_osicbc_wrapper> _osicbc_solver_factory; }
}  // namespace
OSICBC_SolverFactoryInitialiser::OSICBC_SolverFactoryInitialiser() { getWrapper(); }
}  // namespace MiniZinc
