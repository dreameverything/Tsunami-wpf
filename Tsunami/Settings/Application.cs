﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tsunami.Settings
{
    public static class Application
    {
        // how many times torrents must be notified between Tsunami application. In milliseconds. Default value 1000. Should not be lower than 500
        public readonly static int DISPATCHER_INTERVAL = 100;

        // internal Tsunami user_agent
        public readonly static string TSUNAMI_USER_AGENT = "Tsunami/019";
    }
}
