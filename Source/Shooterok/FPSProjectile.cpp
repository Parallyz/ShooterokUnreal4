// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"
#include <Shooterok/MyCharacter.h>
#include <Shooterok/Public/Enemy.h>

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
		CollisionComponent->InitSphereRadius(0.2f);
		
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
		ProjectileMovementComponent->Velocity = FVector(0.0f, 0.0f, 0.0f);
		//ProjectileMovementComponent->InitialSpeed = 0;
	isShooting = false;
	SetActorHiddenInGame(true);
	resetPosition = FVector(resetPosition.X + 10 * Id, resetPosition.Y, resetPosition.Z);
	this->SetActorLocation(resetPosition);
	//	});

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{

	//rojectileMovementComponent->InitialSpeed = 5000.0f;

	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, (TEXT("Velocity %s"), ShootDirection.ToString()));//FString::SanitizeFloat(ProjectileMovementComponent->InitialSpeed)));

}

void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComponent != NULL) && 
		HitComponent != OtherComponent && OtherComponent->GetName()!="ProjectileMeshComponent")
	{
		if (OtherActor->IsA(AEnemy::StaticClass())) {
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("I Hit: %s"), *HitComponent->GetName()));
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Blue, FString::Printf(TEXT("I Hit: %s"), *OtherComponent->GetName()));
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Black, FString::Printf(TEXT("I Hit: %s"), *Hit.Actor->GetName()));

		}
	
		//HitComponent->get
		//AFPSProjectile* proj = Cast<AFPSProjectile>(HitComponent);
		//if (proj->isShooting)
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));

		{
			
		}

		//if (enemy != NULL)
		//{
		//	enemy->DealDamage(25.0f);
		//	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("I Hit: %s"), enemy->healthPoint));

		//}
		//HitComponent->
		/*if (OtherComponent->GetName() != "DamageCollision") {

			try {

				AMyCharacter* character = Cast<AMyCharacter>(OtherActor);

				if (character != NULL)
				{
					character->DealDamage(10.0f);
					if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("I Hit: %s"), character->Health));

				}
			}
			catch ()
			{
				if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("I Hit: %s"), ex.));
			}*/

			}

	//else {

		

		//	character->



	}
	//Destroy();


