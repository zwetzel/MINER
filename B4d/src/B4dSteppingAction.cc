#include "B4SteppingAction.hh"

#include "B4Analysis.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4VProcess.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
B4SteppingAction::B4SteppingAction()
  : G4UserSteppingAction()
  {;}

//  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  B4SteppingAction::~B4SteppingAction()
  {;}

//  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  void B4SteppingAction::UserSteppingAction(const G4Step * theStep)
  {
//    // If you want to do anything for every step, do it here

  // G4cout << "testasdkfjads" << G4endl;
  // if ( theStep->GetPreStepPoint()){
//      G4cout << "Process Name: " << theStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() << G4endl;
//      theStep->GetPostStepPoint()->GetProcessDefinedStep()->DumpInfo();
        G4StepPoint *point1 = theStep -> GetPreStepPoint();
//      G4StepPoint *point2 = theStep -> GetPostStepPoint();


        G4ThreeVector pos1 = point1->GetPosition();
  //      G4ThreeVector pos2 = point2->GetPosition();


        G4TouchableHandle touch1 = point1->GetTouchableHandle();
    //    G4TouchableHandle touch2 = point2->GetTouchableHandle();


        G4VPhysicalVolume* volume1 = touch1 ->GetVolume();
      //  G4VPhysicalVolume* volume2 = touch2 ->GetVolume();


        G4String vol1Name = volume1->GetName();
       // G4String vol2Name = volume2->GetName();


        G4String particleName = theStep->GetTrack()->GetDefinition()->GetParticleName();

G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

        if (vol1Name == "Inner Scoring Sheet" && particleName =="neutron"){
                G4double KinE = point1->GetKineticEnergy();
                analysisManager->FillH1(3,KinE);
                analysisManager->FillH1(1,KinE);



}

   if (vol1Name == "Outer Scoring Sheet" && particleName =="neutron"){

                G4double KinE = point1->GetKineticEnergy();
                analysisManager->FillH1(4,KinE);
                analysisManager->FillH1(1,KinE);
        //      analysisManager->FillNtupleDColumn(0,KinE);
    }

