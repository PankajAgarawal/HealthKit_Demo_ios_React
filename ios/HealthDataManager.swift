//
//  HelthViewController.swift
//  rnDemo
//
//  Created by Pankaj on 05/04/22.
//

import UIKit
import HealthKit

enum HealthkitSetupError: Error {
  case notAvailableOnDevice
  case dataTypeNotAvailable
  case authorizationFailed
}

typealias CompletionHandler = (([[String: Double]]?, Error?) -> Void)
typealias HeartRateCompletionHandler = (([String : Any]?, Error?) -> Void)

@objc class HealthDataManager: NSObject {
  
  let healthStore = HKHealthStore()
  
  var currentHeartRateBPM = Double()
  let heartRateType:HKQuantityType = HKQuantityType.quantityType(forIdentifier: HKQuantityTypeIdentifier.heartRate)!
  var heartRateQuery:HKSampleQuery?
  
  @objc func requestAuth() {
    //1. Check to see if HealthKit Is Available on this device
    guard HKHealthStore.isHealthDataAvailable() else {
      return
    }
    
    //2. Prepare the data types that will interact with HealthKit
    guard
      let dateOfBirth = HKObjectType.characteristicType(forIdentifier: .dateOfBirth),
      let bloodType = HKObjectType.characteristicType(forIdentifier: .bloodType),
      let biologicalSex = HKObjectType.characteristicType(forIdentifier: .biologicalSex),
      let bodyMassIndex = HKObjectType.quantityType(forIdentifier: .bodyMassIndex),
      let height = HKObjectType.quantityType(forIdentifier: .height),
      let bodyMass = HKObjectType.quantityType(forIdentifier: .bodyMass),
      let activeEnergy = HKObjectType.quantityType(forIdentifier: .activeEnergyBurned),
      let basalEnergy = HKObjectType.quantityType(forIdentifier: .basalEnergyBurned),
      let step = HKObjectType.quantityType(forIdentifier: .stepCount),
      let distance = HKObjectType.quantityType(forIdentifier: .distanceWalkingRunning),
      let heartRate = HKObjectType.quantityType(forIdentifier: .heartRate)
        
    else {
      return
    }
    
    //3. Prepare a list of types you want HealthKit to read and write
    let healthKitTypesToWrite: Set<HKSampleType> = [bodyMassIndex,
                                                    activeEnergy,
                                                    basalEnergy,
                                                    HKObjectType.workoutType()]
    let healthKitTypesToRead: Set<HKObjectType> = [dateOfBirth,
                                                   activeEnergy,
                                                   basalEnergy,
                                                   bloodType,
                                                   biologicalSex,
                                                   bodyMassIndex,
                                                   height,
                                                   bodyMass,
                                                   step,
                                                   distance,
                                                   heartRate,
                                                   HKObjectType.workoutType()]
    
    //4. Request Authorization
    HKHealthStore().requestAuthorization(toShare: healthKitTypesToWrite,
                                         read: healthKitTypesToRead) { (success, error) in
    }
  }
  
  @objc func getSteps(From startDate: Date, To endDate: Date, completion: @escaping CompletionHandler) {
    guard let sampleTypeSteps = HKQuantityType.quantityType(forIdentifier: HKQuantityTypeIdentifier.stepCount) else {
      return
    }
    
    performCollectionQuery(sampleType: sampleTypeSteps,
                           startDate: startDate,
                           endDate: endDate,
                           completion: completion)
    
  }
  
  @objc func getDistance(From startDate: Date, To endDate: Date, completion: @escaping CompletionHandler) {
    guard let sampleTypeDistance = HKQuantityType.quantityType(forIdentifier:
                                                                HKQuantityTypeIdentifier.distanceWalkingRunning) else {
      return
    }
    
    performCollectionQuery(sampleType: sampleTypeDistance,
                           startDate: startDate,
                           endDate: endDate,
                           completion: completion)
  }
  
  
  @objc func getBurnCalories(From startDate: Date, To endDate: Date, completion: @escaping CompletionHandler) {
    guard let sampleTypeCalories = HKQuantityType.quantityType(forIdentifier:
                                                                HKQuantityTypeIdentifier.activeEnergyBurned) else {
      return
    }
    performCollectionQuery(sampleType: sampleTypeCalories,
                           startDate: startDate,
                           endDate: endDate,
                           completion: completion)
  }
  
  func getDOB(completion: @escaping CompletionHandler) {
    guard let dob = HKObjectType.characteristicType(forIdentifier:
                                                      HKCharacteristicTypeIdentifier.dateOfBirth) else {
      return
    }
    
    print("Health Data DOB:-",dob)
  }
  
  // Method to get Current heart rate - this only reads data from health kit.
  @objc func getCurrentHeartRates(completion: @escaping HeartRateCompletionHandler) {
    let calendar = NSCalendar.current
    let now = NSDate()
    let components = calendar.dateComponents([.year, .month, .day], from: now as Date)
    
    guard let startDate:NSDate = calendar.date(from: components) as NSDate? else { return }
    var dayComponent    = DateComponents()
    dayComponent.day   = 1
    let endDate:NSDate? = calendar.date(byAdding: dayComponent, to: startDate as Date) as NSDate?
  
    let predicate = HKQuery.predicateForSamples(withStart: startDate as Date, end: endDate as Date?, options: [])
    
    //descriptor
    let sortDescriptors = [
      NSSortDescriptor(key: HKSampleSortIdentifierEndDate, ascending: true)
    ]
    
    heartRateQuery = HKSampleQuery(sampleType: heartRateType, predicate: predicate, limit: HKObjectQueryNoLimit, sortDescriptors: sortDescriptors, resultsHandler: { (query, results, error) in
      
      guard error == nil else { print("error");completion(nil, error); return }
      
      self.collectCurrentHeartRateSample(currentSampleTyple: results) { recordData, error in
      
        // Error Handler manage
        if error != nil {
          completion(nil , error)
        }
        else {
          completion(recordData, nil)
        }
      }
    })
    
    self.healthStore.execute(heartRateQuery!)
  }
  
  // Collect Heart Rate Data
  func collectCurrentHeartRateSample(currentSampleTyple : [HKSample]?, completion: @escaping HeartRateCompletionHandler ){
    
    if currentSampleTyple?.last != nil {
      
      let lastHeartRateSample = currentSampleTyple?.last as! HKQuantitySample
      
      self.currentHeartRateBPM = lastHeartRateSample.quantity.doubleValue(for: HKUnit(from: "count/min"))
      
      DispatchQueue.main.async {
        
        let message = [
          "HeartRateBPM" : "\(self.currentHeartRateBPM)"
        ]
        completion(message, nil)
      }
    }
  }
  
  fileprivate func fetchData(For sampleType: HKQuantityType, from startDate: Date, to endDate: Date, completion: @escaping CompletionHandler) {
    performCollectionQuery(sampleType: sampleType,
                           startDate: startDate,
                           endDate: endDate,
                           completion: completion)
  }
  
  func performCollectionQuery(sampleType: HKQuantityType, startDate: Date, endDate: Date, completion: @escaping CompletionHandler) {
    let predicate = HKQuery.predicateForSamples(withStart: startDate, end: endDate)
    var interval = DateComponents()
    interval.day = 1
    
    let query = HKStatisticsCollectionQuery(quantityType: sampleType,
                                            quantitySamplePredicate: predicate,
                                            options: [.cumulativeSum],
                                            anchorDate: startDate,
                                            intervalComponents: interval)
    
    query.initialResultsHandler = { query, results, error in
      
      if error != nil {
        completion(nil, error)
        return
      }
      
      if let myResults = results {
        
        var data: [[String : Double]] = []
        
        DispatchQueue.main.sync {
          
          myResults.enumerateStatistics(from: startDate, to: endDate) { [weak self] statistics, stop in
            
            if let quantity = statistics.sumQuantity() {
              self?.record(data: &data, date: statistics.endDate, quantity: quantity)
            }
            else {
              if statistics.quantityType.identifier == HKQuantityTypeIdentifier.stepCount.rawValue {
                let quantity = HKQuantity(unit: HKUnit.count(), doubleValue: 0.0)
                self?.record(data: &data, date: statistics.endDate, quantity: quantity)
              }
              else if statistics.quantityType.identifier == HKQuantityTypeIdentifier.distanceWalkingRunning.rawValue {
                let quantity = HKQuantity(unit: HKUnit.meter(), doubleValue: 0.0)
                self?.record(data: &data, date: statistics.endDate, quantity: quantity)
              }
              else if statistics.quantityType.identifier == HKQuantityTypeIdentifier.activeEnergyBurned.rawValue {
                let quantity = HKQuantity(unit: HKUnit.joule(), doubleValue: 0.0)
                self?.record(data: &data, date: statistics.endDate, quantity: quantity)
              }
            }
          }
        }
        completion(data, nil)
      } else {
        completion(nil, HealthkitSetupError.notAvailableOnDevice)
      }
    }
    self.healthStore.execute(query)
  }
  
  func record(data: inout [[String: Double]], date: Date, quantity: HKQuantity) {
    // THE DATA IS BEING STORED IN A DICTIONARY
    // WHERE KEY -> DATE & VALUE -> STEPS/DISTANCE IN (COUNT/KM)
    
    var recordDict: [String: Double] = [:]
    
    if quantity.is(compatibleWith: HKUnit.meter()) {
      let distance = quantity.doubleValue(for: HKUnit.meter()) / 1000.0
      recordDict[date.stringValue] = distance
    }
    
    if quantity.is(compatibleWith: HKUnit.joule()) {
      let count = quantity.doubleValue(for: HKUnit.joule()) / 4184.0 // Convert Joule to Calorie.
      recordDict[date.stringValue] = count
    }
    
    else if quantity.is(compatibleWith: HKUnit.count()) {
      let count = quantity.doubleValue(for: HKUnit.count())
      recordDict[date.stringValue] = count
    }
    
    data.append(recordDict)
  }
  
}


