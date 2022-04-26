import React, { useEffect } from 'react';
import { NativeModules } from 'react-native';
import { Text, View,Button } from 'react-native';

const { HealthStore } = NativeModules;

const App = () => {

useEffect(()=>{
//call authentication

},[])

  const stepButton = async () => {

  HealthStore.getStepsFrom(

    '05-04-2022','15-02-2022',
  ).then((res)=>{
    console.log(`Get steps Data`,res);

  }).catch((error) => {
    console.log(`Error`,error);

  })

  }
  

  const disatcnesButton = async () => {

    HealthStore.getDistanceDataFrom(
  
      '05-04-2022','15-02-2022',
    ).then((res)=>{
      console.log(`Get Distances Data`,res);
  
    }).catch((error) => {
      console.log(`Error`,error);
  
    })
  
    }

    const burnCaloriesButton = async () => {

      HealthStore.getBurnCaloriesFrom(
    
        '05-04-2022','15-02-2022',
      ).then((res)=>{
        console.log(`Get Burn Calories Data`,res);
    
      }).catch((error) => {
        console.log(`Error`,error);
    
      })
    
      }

  return (
    
    <View style={{
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center'
      }}>
      <Text>Welcome To App!</Text>
  <View>

  <Button  
    onPress = {stepButton}  
    title="Get Steps Data"
  />  

<Button  
    onPress = {disatcnesButton}  
    title="Get Distances Data"
  /> 

<Button  
    onPress = {burnCaloriesButton}  
    title="Get Burn Calories Data"
  /> 

</View>
    </View>
  );
}

export default App;