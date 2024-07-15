# LayeredFOW_Demo
UE5 project example for the LayeredFOW plugin. Please UE5.4 or higher version with this project

# Setup

To make it work correctly please add the LayeredFOW plugin to UE5.4, you can follow this [Setup Video](https://www.youtube.com/watch?v=B9pieujL91c).
The demo has a procedural map which is working with another plugin that you can find here [DungeonGenerator](https://github.com/shun126/DungeonGenerator).
Download the plugin and add it into the Plugins folder in the Demo Project, be sure to enable the DungeonGenerator plugin in the LayeredFOW_Demo.uproject file.

# Compilation 

The DungeonGenerator plugins might not compile with Unreal 5.4 because of a virtual function.
You will have to edit this declaration UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances

replace in DungeonTransactionalHierarchicalInstancedStaticMeshComponent.h <br />
```
virtual TArray<int32> AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace = false) override;
```
by <br />
```
virtual TArray<int32> AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace = false, bool bUpdateNavigation = true) override;
```

replace in DungeonTransactionalHierarchicalInstancedStaticMeshComponent.cpp<br />
```
TArray<int32> UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace)
```
by <br />
```
TArray<int32> UDungeonTransactionalHierarchicalInstancedStaticMeshComponent::AddInstances(const TArray<FTransform>& instanceTransforms, bool bShouldReturnIndices, bool bWorldSpace, bool bUpdateNavigation)
```

# Compiled version

You can [Download](https://drive.google.com/file/d/1ZCt-VEQb189YmnXKtGEsg_KU8afXwhld/view?usp=sharing) a compiled version of the demo if you just wanna try it.

# Personal note

Please use everything you find as you please, I'll try to put more comment in the next version ... have fun ! :)

