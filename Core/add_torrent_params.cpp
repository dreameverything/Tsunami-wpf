#include "add_torrent_params.h"


#include <msclr/marshal_cppstd.h>

#include "interop.h"
#include "torrent_info.h"

using namespace Tsunami::Core;

AddTorrentParams::AddTorrentParams()
{
    params_ = new libtorrent::add_torrent_params();
}

AddTorrentParams::AddTorrentParams(libtorrent::add_torrent_params & params)
{
	params_ = new libtorrent::add_torrent_params(params);
}

AddTorrentParams::~AddTorrentParams()
{
    delete params_;
}

System::String^ AddTorrentParams::name::get()
{
    return interop::from_std_string(params_->name);
}

void AddTorrentParams::name::set(System::String^ value)
{
    params_->name = interop::to_std_string(value);
}

System::String^ AddTorrentParams::url::get()
{
	return interop::from_std_string(params_->url);
}

void AddTorrentParams::url::set(System::String^ value)
{
	params_->url = interop::to_std_string(value);
}

System::String^ AddTorrentParams::save_path::get()
{
    return interop::from_std_string(params_->save_path);
}

void AddTorrentParams::save_path::set(System::String^ value)
{
    params_->save_path = interop::to_std_string(value);
}

TorrentInfo^ AddTorrentParams::ti::get()
{
    if(params_->ti)
    {
        return gcnew TorrentInfo(*params_->ti.get());
    }

    return nullptr;
}

void AddTorrentParams::ti::set(TorrentInfo^ value)
{
    params_->ti = boost::shared_ptr<libtorrent::torrent_info>(new libtorrent::torrent_info(*value->ptr()));
}

libtorrent::add_torrent_params* AddTorrentParams::ptr()
{
    return params_;
}

ATPFlags AddTorrentParams::flags::get()
{
	return ATPFlags(params_->flags);
}

void AddTorrentParams::flags::set(ATPFlags flag)
{
	params_->flags = (uint64_t)(System::Object)flag;
}
