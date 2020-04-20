#include "porcupineApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
porcupineApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

porcupineApp::porcupineApp(InputParameters parameters) : MooseApp(parameters)
{
  porcupineApp::registerAll(_factory, _action_factory, _syntax);
}

porcupineApp::~porcupineApp() {}

void
porcupineApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"porcupineApp"});
  Registry::registerActionsTo(af, {"porcupineApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
porcupineApp::registerApps()
{
  registerApp(porcupineApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
porcupineApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  porcupineApp::registerAll(f, af, s);
}
extern "C" void
porcupineApp__registerApps()
{
  porcupineApp::registerApps();
}
