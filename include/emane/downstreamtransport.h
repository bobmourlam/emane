/*
 * Copyright (c) 2013-2014 - Adjacent Link LLC, Bridgewater, New Jersey
 * Copyright (c) 2008-2009 - DRS CenGen, LLC, Columbia, Maryland
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of DRS CenGen, LLC nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EMANEDOWNSTREAMTRANSPORT_HEADER_
#define EMANEDOWNSTREAMTRANSPORT_HEADER_

#include "emane/controlmessage.h"
#include "emane/downstreampacket.h"
#include "emane/upstreampacket.h"

namespace EMANE
{
  class UpstreamTransport;

  /**
   * @class DownstreamTransport
   *
   * @brief DownstreamTransport allows for processing downstream data and 
   * control messages.
   */
  class DownstreamTransport
  {
  public:
    virtual ~DownstreamTransport(){}

    /**
     * Process downstream packet
     *
     * @param pkt Reference to the DownstreamPacket to process
     * @param msgs optional reference to the ControlMessages
     */
    virtual void processDownstreamPacket(DownstreamPacket & pkt,
                                         const ControlMessages & msgs = empty) = 0;

    /**
     * Process downstream control message
     *
     * @param msgs Reference to the ControlMessages
     * 
     */
    virtual void processDownstreamControl(const ControlMessages & msgs) = 0;
    
    /**
     * Set the upstream transport.
     *
     * @param pUpstreamTransport Pointer to the upstream transport
     * of this downstream transport.
     */
    void virtual setUpstreamTransport(UpstreamTransport * pUpstreamTransport)
    {
      pUpstreamTransport_ = pUpstreamTransport; 
    }

    /**
     * Send upstream packet
     *
     * @param pkt Reference to the UpstreamPacket to process
     * @param msgs optional reference to the ControlMessages
     */
    void sendUpstreamPacket(UpstreamPacket & pkt, 
                            const ControlMessages & msgs = empty);

    /**
     * Send upstream control message
     *
     * @param msgs Reference to the ControlMessages
     * 
     */
    void sendUpstreamControl(const ControlMessages & msgs);

    
    static const ControlMessages empty;

  protected:
    
    DownstreamTransport():
      pUpstreamTransport_(0){}

  private:
    UpstreamTransport * pUpstreamTransport_;
  };
}

#include "emane/downstreamtransport.inl"

#endif //EMANEDOWNSTREAMTRANSPORT_HEADER_
