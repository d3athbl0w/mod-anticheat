#include "AnticheatMgr.h"
#include "ScriptMgr.h"

class AnticheatPlayerScript : public PlayerScript
{
public:
	AnticheatPlayerScript() : PlayerScript("AnticheatPlayerScript")
	{
	}

    void OnLogin(Player* player) override
    {
        sAnticheatMgr->HandlePlayerLogin(player);
    }

	void OnLogout(Player* player) override
	{
		sAnticheatMgr->HandlePlayerLogout(player);
	}

    void OnUpdate(Player* player, uint32 p_time) override
    {
        sAnticheatMgr->Update(player, p_time);
    }

    void AnticheatSetSkipOnePacketForASH(Player* player, bool apply) override
    {
        sAnticheatMgr->SetSkipOnePacketForASH(player, apply);
    }

    void AnticheatSetCanFlybyServer(Player* player, bool apply) override
    {
        sAnticheatMgr->SetCanFlybyServer(player, apply);
    }

    void AnticheatSetUnderACKmount(Player* player) override
    {
        sAnticheatMgr->SetUnderACKmount(player);
    }

    void AnticheatSetRootACKUpd(Player* player) override
    {
        sAnticheatMgr->SetRootACKUpd(player);
    }

    void AnticheatSetJumpingbyOpcode(Player* player, bool jump) override
    {
        sAnticheatMgr->SetJumpingbyOpcode(player, jump);
    }

    void AnticheatUpdateMovementInfo(Player* player, MovementInfo const& movementInfo) override
    {
        sAnticheatMgr->UpdateMovementInfo(player, movementInfo);
    }

    bool AnticheatHandleDoubleJump(Player* player, Unit* mover) override
    {
        return sAnticheatMgr->HandleDoubleJump(player, mover);
    }

    bool AnticheatCheckMovementInfo(Player* player, MovementInfo const& movementInfo, Unit* mover, bool jump) override
    {
        return sAnticheatMgr->CheckMovementInfo(player, movementInfo, mover, jump);
    }
};

class AnticheatWorldScript : public WorldScript
{
public:
    AnticheatWorldScript() : WorldScript("AnticheatWorldScript")
    {
    }

    void OnAfterConfigLoad(bool /*reload*/)
    {
        sAnticheatMgr->SetExcludedMaps();
    }
};

void startAnticheatScripts()
{
	new AnticheatPlayerScript();
    new AnticheatWorldScript();
}
