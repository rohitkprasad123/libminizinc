#include <minizinc/solvers/gecode_solverfactory.hh>
#include <minizinc/solvers/gecode_solverinstance.hh>

namespace MiniZinc {
namespace {
void getWrapper() { static Gecode_SolverFactory _gecode_solverfactory; }
}  // namespace
Gecode_SolverFactoryInitialiser::Gecode_SolverFactoryInitialiser() { getWrapper(); }
}  // namespace MiniZinc
