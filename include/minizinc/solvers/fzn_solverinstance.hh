/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 *  Main authors:
 *     Guido Tack <guido.tack@monash.edu>
 */

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include <minizinc/flattener.hh>
#include <minizinc/solver.hh>
//#include <minizinc/solver_instance_base.hh>

namespace MiniZinc {

class FZNSolverOptions : public SolverInstanceBase::Options {
public:
  std::string fzn_solver;
  std::string backend;
  std::vector<std::string> fzn_flags;
  int numSols = 1;
  std::string parallel;
  int fzn_time_limit_ms = 0;
  int solver_time_limit_ms = 0;
  bool fzn_sigint = false;
  /// Number of (optimal) solutions to output
  bool num_optimal = true;
  bool all_optimal = false;

  bool fzn_needs_paths = false;
  bool fzn_output_passthrough = false;

  bool supports_a = false;
  bool supports_n = false;
  bool supports_f = false;
  bool supports_p = false;
  bool supports_s = false;
  bool supports_r = false;
  bool supports_v = false;
  bool supports_t = false;
  bool supports_i = false;
  bool supports_n_o = false;
  bool supports_a_o = false;
  bool supports_cpprofiler = false;
  std::vector<MZNFZNSolverFlag> fzn_solver_flags;
};

class FZNSolverInstance : public SolverInstanceBase {
private:
  std::string _fzn_solver;

protected:
  Model* _fzn;
  Model* _ozn;

public:
  FZNSolverInstance(Env& env, std::ostream& log, SolverInstanceBase::Options* opt);

  ~FZNSolverInstance();

  Status next() { return SolverInstance::ERROR; }

  Status solve();

  void processFlatZinc();

  void resetSolver();

protected:
  Expression* getSolutionValue(Id* id);
};

class FZN_SolverFactory : public SolverFactory {
protected:
  virtual SolverInstanceBase* doCreateSI(Env& env, std::ostream& log,
                                         SolverInstanceBase::Options* opt);

public:
  FZN_SolverFactory();
  virtual SolverInstanceBase::Options* createOptions();
  virtual std::string getDescription(SolverInstanceBase::Options* opt = nullptr);
  virtual std::string getVersion(SolverInstanceBase::Options* opt = nullptr);
  virtual std::string getId();
  virtual bool processOption(SolverInstanceBase::Options* opt, int& i,
                             std::vector<std::string>& argv);
  virtual void printHelp(std::ostream& os);
  void setAcceptedFlags(SolverInstanceBase::Options* opt,
                        const std::vector<MZNFZNSolverFlag>& flags);
};

}  // namespace MiniZinc
