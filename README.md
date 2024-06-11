# LayeredFOW_Demo
UE5 project example for the LayeredFOW plugin.

# Setup

To make it work correctly please add the LayeredFOW plugin into the Plugins folder located in the Content folder.
The demo as a procedural map which is working with another plugin that you can find here https://github.com/shun126/DungeonGenerator.
As for the layeredFOW download the plugin and add it inside the Plugins folder.

#Compilation 

The DungeonGenerator plugins might not compile with Unreal 5.4 because of a virtual function.
You will have to eddit this virtual methode declaration UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances

replace in UDungeonTransactionalHierarchicalInstancedStaticMeshComponent.h
virtual TArray<int32> AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace = false) override;
by 
virtual TArray<int32> AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace = false, bool bUpdateNavigation = true) override;

replace in UDungeonTransactionalHierarchicalInstancedStaticMeshComponent.cpp
TArray<int32> UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace)
by 
TArray<int32> UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace, bool bUpdateNavigation)

#Compiled version

You can dowload a compiled version of the demo here -> https://drive.google.com/file/d/1ZCt-VEQb189YmnXKtGEsg_KU8afXwhld/view?usp=sharing

#Personal note

Please use everything you find as you please, I'll try to put more coment in the next version ... have fun ! :)

