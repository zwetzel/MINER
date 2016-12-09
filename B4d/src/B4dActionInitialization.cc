#include "B4dActionInitialization.hh"
#include "B4PrimaryGeneratorAction.hh"
#include "PGA2.hh"
#include "B4RunAction.hh"
#include "B4dEventAction.hh"
#include "B4SteppingAction.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4dActionInitialization::B4dActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4dActionInitialization::~B4dActionInitialization()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4dActionInitialization::BuildForMaster() const
{
  SetUserAction(new B4RunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4dActionInitialization::Build() const
{
//  SetUserAction(new B4PrimaryGeneratorAction);
  SetUserAction(new PGA2);

