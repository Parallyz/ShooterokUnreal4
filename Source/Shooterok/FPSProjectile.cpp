// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{

		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
		resetPosition = FVector(-10.0f, 0.0f, 0.0f);
		isShooting = false;
	}
	if (!CollisionComponent)
	{

		// Use a sphere as a simple collision representation.
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		// Set the sphere's collision radius.
		CollisionComponent->InitSphereRadius(0.09f);

		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

		// Event called when component hits something.
		CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
		// Set the root component to be the collision component.
		RootComponent = CollisionComponent;
	}
	if (!ProjectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 5000.0f;
		ProjectileMovementComponent->MaxSpeed = 5000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}


	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Mesh/Sphere.Sphere'"));
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/Material/SphereMaterial.SphereMaterial'"));
		if (Material.Succeeded())
		{
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
		}
		RootComponent->SetWorldScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
		ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMeshComponent->SetupAttachment(RootComponent);

		//RootComponent->SetWorldScale3D(FVector(5.0f, 5.0f,5.0f));

	}

	//InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


}

void AFPSProjectile::Reset()
{
	//Async(EAsyncExecution::Thread, [&] {

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Reset"));
		//ProjectileMovementComponent->Velocity = FVector(0.0f, 0.0f, 0.0f);
		//ProjectileMovementComponent->InitialSpeed = 0;
		isShooting = false;
		this->SetActorLocation(resetPosition);
	//	});

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{

	//ProjectileMovementComponent->InitialSpeed = 5000.0f;

	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, (TEXT("Velocity %s"), ShootDirection.ToString()));//FString::SanitizeFloat(ProjectileMovementComponent->InitialSpeed)));

}

void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this)// && OtherComponent->IsSimulatingPhysics())
	{

		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		//OtherActor->Destroy();
		//Reset();
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("HIT"));
	}

	//Destroy();
}

