//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "porcupineTestApp.h"
#include "porcupineApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
porcupineTestApp::validParams()
{
  InputParameters params = porcupineApp::validParams();
  return params;
}

porcupineTestApp::porcupineTestApp(InputParameters parameters) : MooseApp(parameters)
{
  porcupineTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

porcupineTestApp::~porcupineTestApp() {}

void
porcupineTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  porcupineApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"porcupineTestApp"});
    Registry::registerActionsTo(af, {"porcupineTestApp"});
  }
}

void
porcupineTestApp::registerApps()
{
  registerApp(porcupineApp);
  registerApp(porcupineTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
porcupineTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  porcupineTestApp::registerAll(f, af, s);
}
extern "C" void
porcupineTestApp__registerApps()
{
  porcupineTestApp::registerApps();
}
