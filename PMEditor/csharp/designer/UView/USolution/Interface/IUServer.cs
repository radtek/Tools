﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace USolution.Interface
{
    public interface IUServer
    {
        string Name { get; }

        Guid ID { get; }

        List<IUGroup> Groups { get; }
    }
}
